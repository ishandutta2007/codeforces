def cou(s):
    res=0
    for i in range(len(s)-3):
        if s[i:i+4]=="haha":
            res+=1
    return res
def solve():
    var=dict()
    for i in range(int(input())):
        s=input().split()
        if s[1]==":=":
            var[s[0]]=(cou(s[2]),s[2][:3],s[2][-3:])
        else:
            var[s[0]]=(cou(var[s[2]][2]+var[s[4]][1])+var[s[2]][0]+var[s[4]][0]
                       ,(var[s[2]][1]+var[s[4]][1])[:3]
                       ,(var[s[2]][2]+var[s[4]][2])[-3:])
    print(var[s[0]][0])
t=int(input())
for i in range(t):
    solve()