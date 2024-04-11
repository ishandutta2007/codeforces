def main():
    n, m, l = map(int, input().split())
    A = list(map(int, input().split()))
    ans = 0
    for i in range(1, n):
        if A[i] > l >= A[i - 1]:
            ans += 1
    if A[0] > l:
        ans += 1
    babans = []
    for _ in range(m):
        Z = list(map(int, input().split()))
        if len(Z) == 1:
            babans.append(ans)
        else:
            t, p, d = Z
            if p != 1 and p != n:
                if A[p - 1] + d > l >= A[p - 1]:
                    x = A[p - 2]
                    y = A[p]
                    if x > l and y > l:
                        ans -= 1
                    elif x <= l and y <= l:
                        ans += 1
            elif p == 1 and n != 1:
                if A[p - 1] + d > l >= A[p - 1]:
                    if A[p] <= l:
                        ans += 1
            elif p == n and n != 1:
                if A[p - 1] + d > l >= A[p - 1]:
                    if A[p - 2] <= l:
                        ans += 1
            else:
                if A[p - 1] + d > l >= A[p - 1]:
                    ans += 1
            A[p - 1] += d
    print('\n'.join(list(map(str, babans))))


main()