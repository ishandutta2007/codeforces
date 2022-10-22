from collections import deque
a = input().rstrip()                                                                         
q = deque()
for i in a:   
  if len(q) > 0 and i == q[-1]:
    q.pop()  
  else:
    q.append(i)
print('Yes' if len(q) == 0 else 'No')