
def ii():return int(input())
def si():return input()
def li():return list(map(int,input().split()))
def mi():return map(int,input().split())
t=ii()
while(t):
    t-=1
    l=li()
    l.sort()
    s=0
    for i in range(len(l)):
        for j in range(i+1,len(l)):
            for k in range(j+1,len(l)):
                if(l[i]+l[j]+l[k]==l[-1]):
                    print(l[i],l[j],l[k])
                    s=1
                    break
            if(s):
                break
        if(s):
            break