asm(R"(
.text

read_int_fmt: .asciz "%d"
read_str_fmt: .asciz "%s"
print_str_fmt: .asciz "%s\n"
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
    callq read_int
    movq %rax, %rdx

    movq %rdx, %rdi
    movq $8, %rsi
    SafeCall calloc
    movq %rax, %rcx

    movq $1, %r8
.L1:
    callq read_int
    decq %rax
    movl %eax, (%rcx, %r8, 8)
    incq %r8
    cmpq %r8, %rdx
    jg .L1

    movq %rdx, %rdi
    inc %rdi
    movq $1, %rsi
    SafeCall calloc
    movq %rax, %r9

    leaq read_str_fmt(%rip), %rdi
    leaq (%r9), %rsi
    SafeCall scanf

    xorq %r8, %r8
.L2:
    movsbq (%r9, %r8, 1), %rax
    cmpq $'W', %rax
    je .L3
    movq $1, %rax
    jmp .L4
.L3:
    movq $-1, %rax
.L4:
    movl %eax, 4(%rcx, %r8, 8)
    incq %r8

    cmpq %r8, %rdx
    jg .L2

    movq %r9, %rdi
    SafeCall free

    xorq %r9, %r9 # ans
    movq %rdx, %r8

.L5:
    dec %r8
    movslq 4(%rcx, %r8, 8), %rax
    cmpq $0, %rax
    jnz .L6
    inc %r9
.L6:
    movslq (%rcx, %r8, 8), %r10

    movslq 4(%rcx, %r10, 8), %r11
    addq %rax, %r11
    movl %r11d, 4(%rcx, %r10, 8)

    cmpq $0, %r8
    jnz .L5

    movq %rcx, %rdi
    SafeCall free

    movq %r9, %rdi
    callq print_int

.end:
    retq

)");