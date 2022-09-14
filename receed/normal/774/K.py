n=int(input())
s=input()+'0'
i=0
a='aeiouy'
b='oe'
ans=[]
while i<n:
    ans.append(s[i])
    if s[i] in a:
        if s[i] in b and s[i+1]==s[i] and s[i+2]!=s[i]:
            ans.append(s[i])
            i+=2
        else:
            x=i
            while s[i]==s[x]:
                i+=1
    else:
        i+=1
print(''.join(ans))