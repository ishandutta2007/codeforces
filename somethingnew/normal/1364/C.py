def solve():
   n = int(input())
   lst = list(map(int,input().split()))
   svb = []
   svbc = 0
   ans = []
   pos = 0
   for i in range(n):
       if lst[i] == pos:
           svbc += 1
           ans.append(-1)
       elif lst[i] == pos + 1:
           ans.append(pos)
           pos += 1
       elif lst[i] > pos:
           ans.append(pos)
           for x in range(pos+1, lst[i]):
               svb.append(x)
               svbc -= 1
           pos = lst[i]
           if svbc < 0:
               print(-1)
               return
   sh = -1
   for i in ans:
       if i != -1:
           print(i,end=' ')
       else:
           sh += 1
           if sh >= len(svb):
               print(1000000, end=' ')
           else:
               print(svb[sh], end=' ')
   print()
for t in range(1):
    solve()