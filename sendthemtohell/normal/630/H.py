from sys import *
	
MAXN=10**5+228
MOD=10**9+7

def cn5(n):
    return n*(n-1)*(n-2)*(n-3)*(n-4)//120

print(cn5(int(input()))**2*120)