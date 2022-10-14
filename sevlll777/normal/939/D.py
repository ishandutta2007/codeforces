n = int(input())
s = input()
t = input()
gr = {i : set() for i in 'qazwsxedcrfvtgbyhnujmiklop'}
for i in range(n):
    gr[s[i]].add(t[i])
    gr[t[i]].add(s[i])
used = set()
lol = []
for v in gr:
    if v not in used:
        used.add(v)
        q = [v]
        while q:
            g = q.pop()
            for w in gr[g]:
                if w not in used:
                    used.add(w)
                    lol.append((g, w))
                    q.append(w)
print(len(lol))
for a,b in lol:
    print(a, b)