n, k = map(int, input().split())
s = input()
fl = 1
for u in range(n-1, -1, -1):
    if s[:u] == s[-u:]:
        fl = 0
        print(s[:-u]*k+s[-u:])
        break
if fl:
    print(s*k)