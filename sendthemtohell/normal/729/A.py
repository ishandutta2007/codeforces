n=int(input())
s=input()
ans=""
i=0
while i<=n-3:
    if s[i:i+3] != "ogo":
        ans+=s[i]
        i+=1
    else:
        ans+="***"
        i+=3
        while i<=n-2:
            if s[i:i+2] != "go":
                break
            else:
                i+=2
while i<n:
    ans+=s[i]
    i+=1
print(ans)