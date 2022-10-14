n = int(input())
s = input()
t = input()
letter_index_s = {}
letter_index_t = {}
base_s = set()
base_t = set()
for i in set(s):
    letter_index_s[i] = set()
for i in set(t):
    letter_index_t[i] = set()
ans = []
for i in range(n):
    if s[i] != '?':
        letter_index_s[s[i]].add(i + 1)
    else:
        base_s.add(i + 1)
    if t[i] != '?':
        letter_index_t[t[i]].add(i + 1)
    else:
        base_t.add(i + 1)
for i in letter_index_s:
    if i in letter_index_t:
        while len(letter_index_s[i]) and len(letter_index_t[i]):
            z1 = letter_index_s[i].pop()
            z2 = letter_index_t[i].pop()
            ans.append((z1, z2))
for i in letter_index_s:
    for z in letter_index_s[i]:
        if base_t != set():
            ans.append((z, base_t.pop()))
        else:
            break
for i in letter_index_t:
    for z in letter_index_t[i]:
        if base_s != set():
            ans.append((base_s.pop(), z))
        else:
            break
for a in base_s:
    if base_t != set():
        ans.append((a, base_t.pop()))
    else:
        break
print(len(ans))
for i in ans:
    print(i[0], i[1])