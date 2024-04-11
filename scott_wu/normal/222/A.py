#http://codeforces.com/problemset/problem/222/A you start?

n,k=map(int,input().split())
k -= 1
arr = list(int(x) for x in input().split()) #so i think we just find the longest suffix such that they're all the same and check if it starts before k
i = n
for x in range(n-1,-1,-1): #scott this should loop from n-1 to 1? oh ok
  if arr[x] != arr[k]: # should it be arr[x] ? idk
    i = x; break #scott3
if i > k and i < n: 
    print (-1)
else:
    print (0 if i == n else i + 1) #scott i think?