s = input()
t = input()
if len(t) > len(s):
    print(s)
    exit(0)
MOD = 998244353
d = ''
q = t
hashpref = []
hashsuf = []
ans = 0
pow2 = 1
for sq in t[:len(t) // 2 + 1 - len(t) % 2]:
    ans *= 2
    ans %= MOD
    if sq == '1':
        ans += 1
    hashpref.append(ans)
ans = 0
for szq in t[len(t)//2+len(t)%2:][::-1]:
    if szq == '1':
        ans += pow2
        ans %= MOD
    hashsuf.append(ans)
    pow2 *= 2
    pow2 %= MOD
for i in range(len(hashsuf)):
    if hashpref[i] == hashsuf[i]:
        d = t[:i+1]
        q = t[i+1:-i-1]
sz, dz, qz = 0, 0, 0
for i in range(len(s)):
    if s[i] == '0':
        sz += 1
    if i < len(d) and d[i] == '0':
        dz += 1
    if i < len(q) and q[i] == '0':
        qz += 1
so = len(s) - sz
do = len(d) - dz
qo = len(q) - qz
if dz + qz != 0:
    A1 = sz // (dz + qz)
else:
    A1 = float('inf')
if do + qo != 0:
    A2 = so // (do + qo)
else:
    A2 = float('inf')
sz -= min(A1, A2) * (dz + qz)
so -= min(A1, A2) * (do + qo)
hah = d + q
for i in range(min(A1, A2)):
    print(hah, end='')
if sz >= dz and so >= do:
    print(d, end='')
    sz -= dz
    so -= do
for _ in range(sz):
    print('0', end='')
for oo in range(so):
    print('1', end='')