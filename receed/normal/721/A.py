n=int(input())
s=input()+'W'
out=[]
last=0
for i in s:
    if i=='B':
        last+=1
    elif last>0:
        out.append(str(last))
        last=0
print(len(out))
if out:
    print(' '.join(out))