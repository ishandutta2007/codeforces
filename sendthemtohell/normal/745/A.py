s=input()
p=set()
for i in  range(100):
    if s not in p:
        p.add(s)
    s=s[-1]+s[:len(s)-1]
print(len(p))