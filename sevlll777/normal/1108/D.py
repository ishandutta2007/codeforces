n = int(input())
s = input()
s = list(s)
if len(s) <= 2 and len(set(s)) > 1:
    print(0)
    print(''.join(s))
elif len(s) == 2:
    print(1)
    bam = 'RGB'
    print(s[0]+bam[(bam.index(s[0])+1)%3])
else:
    perekras = 0
    for t in range(1, len(s) - 1):
        if s[t-1] == s[t] and s[t] == s[t+1]:
            z = {'R', 'G', 'B'}
            perekras += 1
            z.discard(s[t-1])
            z.discard(s[t+1])
            s[t] = z.pop()
    for t in range(1, len(s) - 1):
        if s[t-1] == s[t] or s[t] == s[t+1]:
            z = {'R', 'G', 'B'}
            perekras += 1
            z.discard(s[t-1])
            z.discard(s[t+1])
            s[t] = z.pop()
    print(perekras)
    print(''.join(s))