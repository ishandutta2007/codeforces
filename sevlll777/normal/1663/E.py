n = int(input())
kek = []
for _ in range(n):
    s = input()
    kek.append(s)
t = "theseus"
for s in kek:
    if s.find(t) != -1:
        print("YES")
        exit(0)
for i in range(n - len(t)):
    for j in range(n):
        ss = ""
        for i0 in range(i, i + len(t)):
            ss += kek[i0][j]
        if ss == t:
            print("YES")
            exit(0)
for i in range(n - len(t)):
    for j in range(n - len(t)):
        ss = ""
        for d in range(len(t)):
            ss += kek[i + d][j + d]
        if ss == t:
            print("YES")
            exit(0)
print("NO")