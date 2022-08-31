n = input()
a = raw_input()
b = raw_input()

print sum (min (abs (ord(i) - ord(j)), 10 - abs (ord(i) - ord(j))) for (i, j) in zip (a, b))