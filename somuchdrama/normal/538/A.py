s = input()
n = len(s)
ans = "NO"
for i in range(n):
    for j in range(i, n + 1):
        if s[:i] + s[j:] == "CODEFORCES":
            ans = "YES"

print(ans)