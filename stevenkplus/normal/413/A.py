n,m,mn,mx = map(int, raw_input().split())
l = [int(x) for x in raw_input().split()]
cmn = min(l)
cmx = max(l)
if cmn < mn or cmx > mx:
  print "Incorrect"
elif cmn != mn and cmx != mx and n - m < 2:
  print "Incorrect"
else:
  print "Correct"