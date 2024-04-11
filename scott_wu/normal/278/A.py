n = int(input())
arr = list (map (int, input().split()))

s,t = map (int, input().split())
s -= 1; t -= 1
if s > t: s, t = t, s

print (min (sum (x for x in arr[s:t]), sum (arr) - sum (x for x in arr[s:t])))