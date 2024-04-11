n = int(input())
s = input()
gen = 'ACTG'
ans = 10000000000
for i in range(n - 3):
    t = s[i:i+4]
    cnt = 0
    for i in range(4):
        x = abs(ord(gen[i]) - ord(t[i]))
        cnt += min(x, 26 - x)
    ans = min(ans, cnt)
print(ans)