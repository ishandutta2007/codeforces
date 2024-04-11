n, m = input().split()
s = ''
n = int(n)
for i in range(len(m) - 1, -1, -1):
    s += m[i]
s = int(s)
print(n + s)