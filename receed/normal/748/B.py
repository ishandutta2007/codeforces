s=input()
s2=input()
a=[set() for i in range(97)]
for i in range(len(s)):
    a[ord(s[i])-97].add(ord(s2[i])-97)
    a[ord(s2[i])-97].add(ord(s[i])-97)
if max([len(i) for i in a])>1:
    print(-1)
else:
    t=set()
    for i in range(26):
        if a[i]!=set():
            o=tuple(sorted([chr(i+97),chr(list(a[i])[0]+97)]))
            if o[0]!=o[1]:
                t.add(o)
    print(len(t))
    for i in t:
        print(i[0],i[1])