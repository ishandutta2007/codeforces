var n,m,i,j,k,ans,l,r:int64;
 function nsd(l,r:int64):int64;
  var k:int64;
   begin
     k:=0;
     while (l>0) and (r>0) do
      if l>r then begin k:=k+l div r; l:=l mod r; end else
       begin k:=k+r div l; r:=r mod l; end;
     exit(k);
   end;
   begin
     read(l,r);
     writeln(nsd(l,r));
   end.