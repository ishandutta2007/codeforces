n=int(input())
s=input()
ans=0
i=0
while i<len(s) and s[i]=="<":
    ans+=1
    i+=1
i=len(s)-1
while i>=0 and s[i]==">":
    ans+=1
    i-=1
print(ans)