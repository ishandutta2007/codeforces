def solve():
   n = int(input())
   lst = list(map(int,input().split()))
   k = 1
   elems = [lst[0]]
   for i in range(1, n-1):
       if lst[i-1] > lst[i] < lst[i+1] or lst[i-1] < lst[i] > lst[i+1]:
           k += 1
           elems.append(lst[i])
   elems.append(lst[-1])
   k += 1
   print(k)
   print(*elems)
for t in range(int(input())):
    solve()