n = int(input())
s = input()
L = []
for _ in range(n):
    a, b = map(int, input().split())
    L.append([a, b])
s = list(map(int, list(s)))
ans = s.count(1)
z = s.count(1)
for i in range(1, 10 ** 5 + 3):
    for j in range(n):
        a, b = L[j]
        if (i - b) % a == 0 and i >= b:
            s[j] = 1 - s[j]
            if s[j] == 0:
                z -= 1
            else:
                z += 1
    ans = max(ans, z)
print(ans)