#from math import *
from sys import *
from decimal import *

def main():
    n,k=(int(z) for z in stdin.readline().split())
    d=[]
    nm=[0]*n
    bt1=[False]*(n+1)
    bt2=[False]*(n+1)
    bt2[-1]=True
    nam=dict()
    nam["?"]=-1
    for i in range(n):
        fl=0
        s=stdin.readline()[:-1].split(" := ")
        nam[s[0]]=i
        if len(s[1])<30:
            for j in s[1]:
                if j=="A":
                    fl=1
                    break
                if j=="X":
                    fl=2
                    break
                if j=="O":
                    fl=3
                    break
        if fl==0:
            d.append([nam[s[0]],s[1]])
        elif fl==1:
            d.append([i]+[nam[z] for z in s[1].split(" AND ")])
        elif fl==2:
            d.append([i]+[nam[z] for z in s[1].split(" XOR ")])
        else:
            d.append([i]+[nam[z] for z in s[1].split(" OR ")])
        nm[i]=fl
    
    mn=[False]*k
    mx=[False]*k
    for i in range(k):
        r1=0
        r2=0
        for ololo in range(n):
            eq=d[ololo]
            #print(bt1,bt2)
            if nm[ololo]==0:
                bt1[eq[0]]=bool(int(eq[1][i]))
                r1+=int(eq[1][i])
                bt2[eq[0]]=bool(int(eq[1][i]))
                r2+=int(eq[1][i])
                #print(int(bool(eq[1][i])))
            elif nm[ololo]==1:
                if bt1[eq[1]]==bt1[eq[2]]==True:
                    bt1[eq[0]]=True
                    r1+=1
                else:
                    bt1[eq[0]]=False
                if bt2[eq[1]]==bt2[eq[2]]==True:
                    bt2[eq[0]]=True
                    r2+=1
                else:
                    bt2[eq[0]]=False
            elif nm[ololo]==2:
                #print(bt1[eq[1]],eq,bt1[eq[2]])
                if bt1[eq[1]]!=bt1[eq[2]]:
                    bt1[eq[0]]=True
                    r1+=1
                else:
                    bt1[eq[0]]=False
                #print("wev",int(bt1[eq[0]]))
                if bt2[eq[1]]!=bt2[eq[2]]:
                    bt2[eq[0]]=True
                    r2+=1
                else:
                    bt2[eq[0]]=False
                #print('wfeaerhbjds',int(bt2[eq[0]]))
            else:
                if bt1[eq[1]]!=bt1[eq[2]] or bt1[eq[2]]!=False:
                    bt1[eq[0]]=True
                    r1+=1
                else:
                    bt1[eq[0]]=False
                if bt2[eq[1]]!=bt2[eq[2]] or bt2[eq[2]]!=False:
                    bt2[eq[0]]=True
                    r2+=1
                else:
                    bt2[eq[0]]=False
        #print(r1,r2,mn,mx)
        if r2>r1:
            mn[i]=True
        elif r2<r1:
            mx[i]=True
    
    stdout.write(''.join( (str(int(z)) for z in mx) ) + '\n')
    stdout.write(''.join( (str(int(z)) for z in mn) ) + '\n')
    
main()