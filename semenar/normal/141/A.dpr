program SantaMoroz;
var i, exists: integer;
str1, str2, strsum, strempty: string;
begin
readln(str1);
readln(str2);
readln(strsum);
strempty:='';
for i:=1 to length(strsum) do
  strempty:=strempty+' ';
exists := 1;
i := 1;
while (exists=1) and (i<=length(str1)) do
  begin
  if (pos(str1[i],strsum)=0) then exists:=0 else strsum[pos(str1[i],strsum)]:=' ';
  i:=i+1;
  end;
i := 1;
while (exists=1) and (i<=length(str2)) do
  begin
  if (pos(str2[i],strsum)=0) then exists:=0 else strsum[pos(str2[i],strsum)]:=' ';
  i:=i+1;
  end;
if exists=0 then writeln('NO')
else if strsum=strempty then writeln('YES') else writeln('NO');
end.