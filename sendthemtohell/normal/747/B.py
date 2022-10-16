from sys import *

n=int(input())
s=input()
d=dict()
d["A"]=0
d["C"]=0
d["G"]=0
d["T"]=0
d["?"]=0
for i in s:
    d[i]+=1
if n%4:
    print("===")
else:
    n//=4
    ans=""
    j=0
    for i in ["A","C","G","T"]:
        if d[i]>n:
            print("===")
            exit(0)
        while d[i]<n:
            if j==len(s):
                print("===")
                exit (0)
            if s[j]=="?":
                ans+=i
                d[i]+=1
            else:
                ans+=s[j]
            j+=1
    while j <len (s):
        ans+=s[j]
        j+=1
    print(ans)