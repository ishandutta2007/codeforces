n, q = map(int, input().split())
s = input()
c0 = [0]
for i in s:
    c0.append(c0[-1] + (i == '0'))
M = 10 ** 9 + 7
ans = []
for i in range(q):
    l, r = map(int, input().split())
    z = c0[r] - c0[l - 1]
    on = (r - l + 1) - z
    ans.append((pow(2, on, M) - 1) * pow(2, z, M) % M)
print('\n'.join(list(map(str, ans))))