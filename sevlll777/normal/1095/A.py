n = int(input())
s = input()
ans = ""
i = 0
y = 0
while i < n:
    ans += s[i]
    y += 1
    i += y
print(ans)