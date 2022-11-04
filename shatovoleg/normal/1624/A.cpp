asm(R"(

.text
printf_fmt: .asciz "%d\n"
scanf_fmt: .asciz "%d"


.global main
main:
    pushq %rbp
    movq %rsp, %rbp

    andq $-16, %rsp
    subq $16, %rsp

    leaq scanf_fmt(%rip), %rcx
    leaq (%rsp), %rdx
    subq $32, %rsp
    call scanf
    addq $32, %rsp

    movq %rbx, 8(%rsp)
    xorq %rbx, %rbx
    movl (%rsp), %ebx


.L3:
    call solve
    dec %rbx
    jnz .L3

    movq 8(%rsp), %rbx

    movq %rbp, %rsp
    popq %rbp
    xorq %rax, %rax
    ret

solve:
    pushq %rbp
    movq %rsp, %rbp

    andq $-16, %rsp

    subq $48, %rsp

    leaq scanf_fmt(%rip), %rcx
    leaq 32(%rsp), %rdx
    subq $32, %rsp
    call scanf
    addq $32, %rsp

    movq $0, 24(%rsp)
    movq $1000000666, 16(%rsp)

    movq %rbx, (%rsp)
    xorq %rbx, %rbx
    movl 32(%rsp), %ebx

.L1:
    leaq scanf_fmt(%rip), %rcx
    leaq 8(%rsp), %rdx
    subq $32, %rsp
    call scanf
    addq $32, %rsp

    xorq %rax, %rax
    movl 8(%rsp), %eax

    cmp %rax, 24(%rsp)
    jnl .not_mx
    movq %rax, 24(%rsp)
.not_mx:

    cmp %rax, 16(%rsp)
    jng .not_mn
    movq %rax, 16(%rsp)
.not_mn:

    dec %rbx
    jnz .L1

    movq (%rsp), %rbx

    movq 24(%rsp), %rax
    subq 16(%rsp), %rax

    leaq printf_fmt(%rip), %rcx
    movq %rax, %rdx
    subq $32, %rsp
    call printf
    addq $32, %rsp

    movq %rbp, %rsp
    popq %rbp
    ret

)");