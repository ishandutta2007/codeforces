n = int(input())
A = list(map(int, input().split()))
if n == len(set(A)):
    print(0)
    exit(0)
l = 0
r = n
G = [set()]
s1 = set()
for i in range(n):
    s1.add(A[i])
    G.append(s1.copy())
while r - l > 1:
    gg = False
    x = (l + r) // 2
    H = []
    s2 = set()
    for i in range(n - 1, x - 1, -1):
        if s2.intersection(G[i - x + 1]) == set() and len(s2) == n - i - 1 and len(G[i - x + 1]) == i - x + 1:
            gg = True
            break
        s2.add(A[i])
    if len(s2) == n - x:
        gg = True
    if gg:
        r = x
    else:
        l = x
print(l + 1)