n = int(raw_input())
a = map(int , raw_input().split())
b = map(int , raw_input().split())
s , t = b[0] - 1 , b[1] - 1
if s > t:
    s , t = t , s
res = sum(a)
print min(sum(a[s:t]) , res - sum(a[s:t]))