n, k = map(int, input().split())
f = True
s = input()
for i in s:
    if s.count(i) > k:
        f = False

print("YES" if f else "NO")