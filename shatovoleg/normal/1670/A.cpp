asm(R"(
.text

read_int_fmt: .asciz "%d"
read_str_fmt: .asciz "%s"
print_int_fmt: .asciz "%d\n"
.ifdef .text
print_long_long_fmt: .asciz "%lld\n"
.else
print_long_long_fmt: .asciz "%I64d\n"
.endif

NO: .asciz "NO\n"
YES: .asciz "YES\n"
KEK: .asciz "KEK\n"

.macro SAVE
    pushq %rcx
    pushq %rdx
    pushq %r8
    pushq %r9
    pushq %r10
    pushq %r11
.endm

.macro LOAD
    popq %r11
    popq %r10
    popq %r9
    popq %r8
    popq %rdx
    popq %rcx
.endm

.macro SafeCall func
    SAVE
    .ifndef .text
    movq %rcx, %r9
    movq %rdx, %r8
    movq %rsi, %rdx
    movq %rdi, %rcx
    subq $32, %rsp
    callq \func
    addq $32, %rsp
    .else
    callq \func
    .endif
    LOAD
.endm

read_int:
    leaq read_int_fmt(%rip), %rdi
    subq $8, %rsp
    leaq (%rsp), %rsi
    SafeCall scanf
    movslq (%rsp), %rax
    addq $8, %rsp
    ret

print_int:
    movq %rdi, %rsi
    leaq print_int_fmt(%rip), %rdi
    SafeCall printf
    ret

.global main
main:
    pushq %rbx
    callq read_int
    movq %rax, %rbx

.L0:
    callq solve
    dec %rbx
    jnz .L0

    popq %rbx
    xorq %rax, %rax

    retq

solve:
    pushq %rbx
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    callq read_int
    movq %rax, %rbx
    leaq (%rbx, %rbx, 4), %rax
    subq %rbx, %rax
    movq %rax, %rdi
    SafeCall malloc
    movq %rax, %r10

    movq $0, %r8
    movq $0, %r9
.L1:
    callq read_int
    movl %eax, (%r10, %r8, 4)
    cmpq $0, %rax

    jge .positive
    inc %r9
.positive:

    inc %r8
    cmpq %rbx, %r8
    jl .L1

    cmpq $1, %rbx
    je .YES

    movq $0, %r8
.L2:
    movslq (%r10, %r8, 4), %rdi
    SafeCall abs

    cmpq $0, %r9
    je .should_be_positive
    movq %rax, %rdi
    xorq %rax, %rax
    subq %rdi, %rax
    dec %r9
.should_be_positive:

    movl %eax, (%r10, %r8, 4)

    inc %r8
    cmpq %rbx, %r8
    jl .L2

    movq $1, %r8
.L3:
    movslq -4(%r10, %r8, 4), %rdi
    movslq (%r10, %r8, 4), %rsi
    cmpq %rdi, %rsi
    jl .NO

    inc %r8
    cmpq %rbx, %r8
    jl .L3

.YES:
    leaq YES(%rip), %rdi
    SafeCall printf
    jmp .end

.NO:
    leaq NO(%rip), %rdi
    SafeCall printf

.end:
    movq %r10, %rdi
    SafeCall free
    movq %rbp, %rsp
    popq %rbp
    popq %rbx
    retq

)");