s=input()+'U'
mx=0
last=-1
for i in range(len(s)):
    if s[i] in 'EIOUAY':
        mx=max(mx,i-last)
        last=i
print(mx)