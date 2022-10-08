s=str(raw_input())
t=""
l=len(s)
i=0
while i<l:
    if s[i]==".":
        t+="0"
        i+=1
    else:
        i+=1
        if s[i]==".":
            t+="1"
        else:
            t+="2"
        i+=1
print t