n,ice=(int(z) for z in input().split())
bad=0
for i in range(n):
    s=input().split()
    if s[0]=="+":
        ice+=int(s[1])
    else:
        want=int(s[1])
        if ice>=want:
            ice-=want
        else:
            bad+=1
print(ice,bad)