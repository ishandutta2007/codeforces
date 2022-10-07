s = raw_input()
a, b = "",""
cnt = 0

for i in s:
  if i == '0':
    b += i
  else:
    if len(a) > len(b) or (len(a) == len(b) and a >= b):
      cnt += 1
    else: cnt = 1
    a += b
    b = i
if len(a) > len(b) or (len(a) == len(b) and a >= b):
  cnt += 1
else: cnt = 1
print cnt