from sys import *
	
MAXN=10**5+228
MOD=10**9+7

a,b=(int(z) for z in input().split())
print(min(a,b,(a+b)//3))