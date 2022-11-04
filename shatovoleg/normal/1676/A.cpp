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
    pushq %rsi
    pushq %rdi
    callq read_int
    movq %rax, %rbx

.L0:
    callq solve
    dec %rbx
    jnz .L0

    popq %rdi
    popq %rsi
    popq %rbx
    xorq %rax, %rax

    retq

solve:
    subq $8, %rsp
    leaq read_str_fmt(%rip), %rdi
    leaq (%rsp), %rsi
    SafeCall scanf
    xorq %rax, %rax

    movsbq (%rsp), %rcx
    addq %rcx, %rax
    movsbq 1(%rsp), %rcx
    addq %rcx, %rax
    movsbq 2(%rsp), %rcx
    addq %rcx, %rax

    movsbq 3(%rsp), %rcx
    subq %rcx, %rax
    movsbq 4(%rsp), %rcx
    subq %rcx, %rax
    movsbq 5(%rsp), %rcx
    subq %rcx, %rax

    cmpq $0, %rax
    jne .NO

.YES:
    leaq YES(%rip), %rdi
    SafeCall printf
    jmp .end

.NO:
    leaq NO(%rip), %rdi
    SafeCall printf

.end:
    addq $8, %rsp
    retq

)");