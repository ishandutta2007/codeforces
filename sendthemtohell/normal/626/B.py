def cnt(a,e):
    res=0
    for i in s:
        if i==e:
            res+=1
    return res

n=input()
s=input()
a1=cnt(s,"R")
a2=cnt(s,"G")
a3=cnt(s,"B")
if a1 and not a2 and not a3:
    print("R")
elif a2 and not a1 and not a3:
    print("G")
elif a3 and not a2 and not a1:
    print("B")
elif a1+a2+a3==2:
    se=set(["R","G","B"])
    se-=set(s)
    for i in se:
        print(i)
elif a1 > 1 and a2+a3==1:
    print("BG")
elif a2 > 1 and a1+a3==1:
    print("BR")
elif a3 > 1 and a1+a2==1:
    print("GR")
else:
    print("BGR")