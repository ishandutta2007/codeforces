from sys import stdin
input=stdin.readline
q = int(input())
for i in range(q):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    r = [j + 1 for j in range(n) if a[j] % 2 == 1]
    if len(r) >= k and len(r) % 2 == k % 2:
        print("YES")
        r[len(r) - 1] = n
        print(*r[len(r) - k:])
    else:
        print("NO")