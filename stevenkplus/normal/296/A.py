n=int(input())
s=input().split()
print("YES"if all([s.count(i)*2-1<=n for i in s])else"NO")