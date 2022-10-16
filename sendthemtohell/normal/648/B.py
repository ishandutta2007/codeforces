n=int(input())
s=[int(z) for z in input().split()]
s.sort()
for i in range(n):
	print(s[i],s[2*n-i-1])