n=int(input())
s=input()
ans=1
ud=''
lr=''
for i in range(len(s)):
    if s[i] in ['U','D']:
        if ud and ud != s[i]:
            ans+=1
            ud=s[i]
            lr=''
        elif not ud:
            ud=s[i]
    else:
        if lr and lr != s[i]:
            ans+=1
            ud=''
            lr=s[i]
        elif not lr:
            lr=s[i]
    assert lr in ['L','R','']
    assert ud in ['U','D','']
print(ans)