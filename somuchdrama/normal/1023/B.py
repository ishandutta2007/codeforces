n,k = map(int, input().split())
cnt=(k-1)//2
a=min(cnt,n-(k+2)//2+1)
print(max(0,a))