n = int(input())
s = input()
if len(s) <= 2 and len(set(s)) > 1:
    print(0)
    print(s)
elif len(s) == 2:
    print(1)
    bam = 'RGB'
    print(s[0]+bam[(bam.index(s[0])+1)%3])
else:
    o1 = {'R': 0, 'G': 0, 'B': 0}
    o2 = {'R': 0, 'G': 0, 'B': 0}
    o3 = {'R': 0, 'G': 0, 'B': 0}
    for t in range(len(s)):
        if t%3 == 0:
            o1[s[t]] += 1
        elif t%3 == 1:
            o2[s[t]] += 1
        else:
            o3[s[t]] += 1
    m1 = 0
    kwek = ''
    for girl in ('RGB', 'RBG', 'BRG', 'BGR', 'GRB', 'GBR'):
        z = o1[girl[0]]+o2[girl[1]]+o3[girl[2]]
        if z > m1:
            m1 = z
            kwek = girl
    print(len(s) - m1)
    for t in range(len(s)):
        print(kwek[t%3], end='')