n = int(input())
s = input()
hex = 0
for i in range(n // 2 + 1):
    if s[:i] == s[i:2*i]:
        hex = i
print(n - max(0, hex - 1))