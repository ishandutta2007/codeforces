s=input()
ans=""
a=1
i=0
while i<len(s):
    if s[i]!="a":
        while i<len(s) and s[i]!="a":
            ans+=chr(ord(s[i])-1)
            i+=1
        while i<len(s):
            ans+=s[i]
            i+=1
        break
    elif i==len(s)-1:
        ans+="z"
        i+=1
    else:
        ans+="a"
        i+=1
print(ans)