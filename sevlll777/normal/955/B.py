s=input()
z = set(s)
fl=0
for t in z:
    if s.count(t)==1:
        fl+=1
if len(z) == 4 or (len(z) == 2 and fl == 0) or (len(z) == 3 and fl <= (len(s) - 2)):
    print('Yes')
else:
    print('No')