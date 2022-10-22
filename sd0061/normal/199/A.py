n = input()
if n == 0:
  print 0 , 0 , 0 
else:
    a = 0
    b = 1
    while (1):
        if a + b == n:
            print 0 , a , b
            break
        a , b = b , a + b