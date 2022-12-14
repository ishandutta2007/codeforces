n,b=map(int,input().split())
def Q():
  a=[0];l=0
  for i in range(n):
    t,d=map(int,input().split())
    a+=[t+d if t>a[-1] else a[-1]+d]
    while a[l]<=t: l+=1
    if len(a)-l-1>b: a.pop(); yield "-1"
    else: yield str(a[-1])
print(' '.join(Q()))