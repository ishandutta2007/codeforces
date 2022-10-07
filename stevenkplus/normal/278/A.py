n = int(input())
s = list(map(int,input().split()))
a,b=  map(lambda x:int(x)-1, input().split())
if a > b: a,b=b,a
tot = sum(s[a:b])
print (min(tot, sum(s)-tot))