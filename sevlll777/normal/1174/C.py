n = int(input())
is_prime = [-1] * (n - 1)
u = 1
for d in range(2, n + 1):
    if is_prime[d - 2] == -1:
        is_prime[d - 2] = u
        u += 1
    for comp in range(2 * d, n + 1, d):
        is_prime[comp - 2] = is_prime[d - 2]
print(*is_prime)