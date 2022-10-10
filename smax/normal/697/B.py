line = input()
a = line.split(".")[0]
b = line.split(".")[1].split("e")[0]
c = int(line.split(".")[1].split("e")[1])

b += 1000 * '0'
a += b[:c]
b = b[c:]

if a.count('0') < len(a):
  pos = 0
  while a[pos] == '0':
    pos += 1
  a = a[pos:]

if b.count('0') == len(b):
  print(a)
else:
  pos = len(b) - 1
  while b[pos] == '0':
    pos -= 1
  print(a + "." + b[:pos+1])