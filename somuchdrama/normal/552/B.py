n = int(input())
ans = 0
A = [9 * 10 ** i for i in range(10)]
for i in range(10):
    if n <= A[i]:
        print(ans + n * (i + 1))
        break
    else:
        ans += A[i] * (i + 1)
        n -= A[i]