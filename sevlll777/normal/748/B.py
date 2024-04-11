s = input()
t = input()
pes = set()
yyy = set()
ll = 0
for i in range(len(s)):
    z = min(s[i], t[i])
    h = max(s[i], t[i])
    a = ord(z) * 1000 + ord(h)
    pes.add(a)
    if s[i] == t[i] and s[i] not in yyy:
        yyy.add(s[i])
        ll += 1
dj = set()
for i in pes:
    dj.add(chr(i // 1000))
    dj.add(chr(i % 1000))
if len(dj) == 2 * len(pes) - ll:
    ans=[]
    for i in pes:
        if chr(i // 1000) != chr(i % 1000):
            ans.append([chr(i // 1000), chr(i % 1000)])
    print(len(ans))
    for i in ans:
        print(i[0], i[1])
    exit(0)
print(-1)